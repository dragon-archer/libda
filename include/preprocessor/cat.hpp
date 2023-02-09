/**
 * @file      cat.hpp
 * @brief     Implement DA_CAT
 * @version   0.1
 * @author    dragon-archer
 *
 * @copyright Copyright (c) 2023
 */

#ifndef _LIBDA_PREPROCESSOR_CAT_HPP_
#define _LIBDA_PREPROCESSOR_CAT_HPP_

#include "base.hpp"
#include "fold.hpp"

/**
 * @brief Concat everything
 * 
 * This macro is the super version of DA_CAT2(), and can concat any number of params
 */
#define DA_CAT(...) __VA_OPT__(DA_FOLD(DA_CAT2, __VA_ARGS__))

#endif // _LIBDA_PREPROCESSOR_CAT_HPP_
