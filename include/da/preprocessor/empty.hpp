/**
 * @file      empty.hpp
 * @brief     Implement DA_IS_EMPTY
 * @version   0.1
 * @author    dragon-archer
 *
 * @copyright Copyright (c) 2023
 */

#ifndef _LIBDA_PREPROCESSOR_EMPTY_HPP_
#define _LIBDA_PREPROCESSOR_EMPTY_HPP_

#include <da/preprocessor/base.hpp>
#include <da/preprocessor/seq.hpp>

/**
 * @brief Detect whether the argument is empty
 */
#define DA_IS_EMPTY(...)   DA_IS_EMPTY_I(__VA_ARGS__)
#define DA_IS_EMPTY_I(...) DA_SEQ_HEAD(__VA_OPT__(0, ) 1)

#endif // _LIBDA_PREPROCESSOR_EMPTY_HPP_