#ifndef _LIBS_LOG_LOG_PERMISSION_H
#define _LIBS_LOG_LOG_PERMISSION_H

#include <android/log.h>
#include <log/log_id.h>

/*
 * Normally we strip the effects of ALOGV (VERBOSE messages),
 * LOG_FATAL and LOG_FATAL_IF (FATAL assert messages) from the
 * release builds be defining NDEBUG.  You can modify this (for
 * example with "#define LOG_NDEBUG 0" at the top of your source
 * file) to change that behavior.
 */

#ifndef LOG_NDEBUG
#ifdef NDEBUG
#define LOG_NDEBUG 1
#else
#define LOG_NDEBUG 0
#endif
#endif

#ifndef __predict_false
#define __predict_false(exp) __builtin_expect((exp) != 0, 0)
#endif

// ---------------------------------------------------------------------
  
/*
 * Simplified macro to send a verbose permission log message using the current LOG_TAG.
 */
#ifndef PLOGV
#define __PLOGV(...) \
    ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__))
#if LOG_NDEBUG
#define PLOGV(...) do { if (0) { __PLOGV(__VA_ARGS__); } } while (0)
#else
#define PLOGV(...) __PLOGV(__VA_ARGS__)
#endif
#endif

#ifndef PLOGV_IF
#if LOG_NDEBUG
#define PLOGV_IF(cond, ...)   ((void)0)
#else
#define PLOGV_IF(cond, ...) \
    ( (__predict_false(cond)) \
    ? ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif
#endif

/*
 * Simplified macro to send a debug permission log message using the current LOG_TAG.
 */
#ifndef PLOGD
#define PLOGD(...) \
    ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#endif

#ifndef PLOGD_IF
#define PLOGD_IF(cond, ...) \
    ( (__predict_false(cond)) \
    ? ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

/*
 * Simplified macro to send an info permission log message using the current LOG_TAG.
 */
#ifndef PLOGI
#define PLOGI(...) \
    ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#endif

#ifndef PLOGI_IF
#define PLOGI_IF(cond, ...) \
    ( (__predict_false(cond)) \
    ? ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

/*
 * Simplified macro to send a warning permission log message using the current LOG_TAG.
 */
#ifndef PLOGW
#define PLOGW(...) \
    ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))
#endif

#ifndef PLOGW_IF
#define PLOGW_IF(cond, ...) \
    ( (__predict_false(cond)) \
    ? ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

/*
 * Simplified macro to send an error permission log message using the current LOG_TAG.
 */
#ifndef PLOGE
#define PLOGE(...) \
    ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#endif

#ifndef PLOGE_IF
#define PLOGE_IF(cond, ...) \
    ( (__predict_false(cond)) \
    ? ((void)__android_log_buf_print(LOG_ID_PERMISSION, ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

#endif /* _LIBS_LOG_LOG_PERMISSION_H */
