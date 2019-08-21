/**
 * @file utils.h
 *
 * @brief Mathematic utilitary functions
 */

#ifndef __UTILS_H__
#define __UTILS_H__

/*****************************************
 * Public Macros
 *****************************************/

#define abs(x) ((x) > 0 ? (x) : -(x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define constrain(v, x, y) ((v) < (x) ? (x) : ((v) > (y) ? (y) : (v)))

/*****************************************
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Maps an integer value from one scale to another
 *
 * @param former_value Value in former scale
 * @param former_min   Former scale minimum value
 * @param former_max   Former scale maximum value
 * @param new_min      New scale minimum value
 * @param new_max      New scale maximum value
 *
 * @return Value in new scale
 */
int map(int former_value, int former_min, int former_max, int new_min, int new_max);

#endif // __UTILS_H__
