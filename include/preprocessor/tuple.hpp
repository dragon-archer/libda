/**
 * @file      tuple.hpp
 * @brief     Basic tuple operations
 * @version   0.1
 * @author    dragon-archer
 *
 * @copyright Copyright (c) 2023
 */

#ifndef _LIBDA_PREPROCESSOR_TUPLE_HPP_
#define _LIBDA_PREPROCESSOR_TUPLE_HPP_

#include "base.hpp"
#include "conditional.hpp"
#include "empty.hpp"
#include "seq.hpp"

/**
 * @brief Detect whether it is a tuple
 */
#define DA_IS_TUPLE(x) DA_IS_EMPTY(DA_EMPTY x)

/**
 * @brief Unpack tuple
 */
#define DA_TUPLE_UNPACK(x)     DA_TUPLE_UNPACK_I x
#define DA_TUPLE_UNPACK_I(...) __VA_ARGS__

/**
 * @brief Unpack if it is a tuple, else do nothing
 */
#define DA_TUPLE_UNPACK_OPT(x) DA_IF(DA_IS_TUPLE(x), DA_TUPLE_UNPACK, DA_IDENTITY)(x)

/**
 * @brief Get the size of a tuple
 */
#define DA_TUPLE_SIZE(x) DA_CNT(DA_TUPLE_UNPACK(x))

/**
 * @brief Get nth element of a tuple
 */
#define DA_TUPLE_GET(n, x) DA_SEQ_GET(n, DA_TUPLE_UNPACK(x))

#endif // _LIBDA_PREPROCESSOR_TUPLE_HPP_
