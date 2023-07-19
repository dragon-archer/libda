/* SPDX-License-Identifier: MIT */
/**
 * @file      hash.hpp
 * @brief     Hash function
 * @version   0.1
 * @author    dragon-archer
 *
 * @copyright Copyright (c) 2023 dragon-archer
 */

#ifndef _DA_HASH_HPP_
#define _DA_HASH_HPP_

#include <da/config.hpp>
#include <cstring>
#include <string_view>

DA_BEGIN_NAMESPACE

inline size_t fnv1a_hash(const uint8_t* p, size_t len) noexcept {
	constexpr size_t fnv_prime        = 0x00000100000001B3;
	constexpr size_t fnv_offset_basis = 0xCBF29CE484222325;

	size_t v = fnv_offset_basis;
	while(len--) {
		v ^= static_cast<size_t>(*p);
		v *= fnv_prime;
		++p;
	}
	return v;
}

template<typename T>
inline size_t hash(const T& x) noexcept {
	return fnv1a_hash(reinterpret_cast<const uint8_t*>(&x), sizeof(T));
}

template<>
inline size_t hash(const std::string_view& x) noexcept {
	return fnv1a_hash(reinterpret_cast<const uint8_t*>(x.data()), x.size());
}

template<>
inline size_t hash(const char* const& x) noexcept {
	return fnv1a_hash(reinterpret_cast<const uint8_t*>(x), std::strlen(x));
}

template<size_t N>
inline size_t hash(const char (&x)[N]) noexcept {
	return fnv1a_hash(reinterpret_cast<const uint8_t*>(x), N - 1); // Discard '\0'
}

DA_END_NAMESPACE

#endif // _DA_HASH_HPP_