/*
** Copyright 2013-2014, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
 * This work was modified by Two Six Labs, LLC and is sponsored by a subcontract agreement with
 * Raytheon BBN Technologies Corp. under Prime Contract No. FA8750-16-C-0006 with the Air Force
 * Research Laboratory (AFRL).
 *
 * The Government has unlimited rights to use, modify, reproduce, release, perform, display, or disclose
 * computer software or computer software documentation marked with this legend. Any reproduction of
 * technical data, computer software, or portions thereof marked with this legend must also reproduce
 * this marking.
 *
 * Copyright (C) 2020 Two Six Labs, LLC.  All rights reserved.
 */

#include <string.h>

#include <log/log.h>

#include "log_portability.h"

/* In the future, we would like to make this list extensible */
static const char* LOG_NAME[LOG_ID_MAX] = {
      /* clang-format off */
  [LOG_ID_MAIN] = "main",
  [LOG_ID_RADIO] = "radio",
  [LOG_ID_EVENTS] = "events",
  [LOG_ID_SYSTEM] = "system",
  [LOG_ID_CRASH] = "crash",
  [LOG_ID_STATS] = "stats",
  [LOG_ID_SECURITY] = "security",
  [LOG_ID_KERNEL] = "kernel",
  [LOG_ID_PERMISSION] = "permission",

  /* clang-format on */
};

LIBLOG_ABI_PUBLIC const char* android_log_id_to_name(log_id_t log_id) {
  if (log_id >= LOG_ID_MAX) {
    log_id = LOG_ID_MAIN;
  }
  return LOG_NAME[log_id];
}

LIBLOG_ABI_PUBLIC log_id_t android_name_to_log_id(const char* logName) {
  const char* b;
  int ret;

  if (!logName) {
    return -1; /* NB: log_id_t is unsigned */
  }
  b = strrchr(logName, '/');
  if (!b) {
    b = logName;
  } else {
    ++b;
  }

  for (ret = LOG_ID_MIN; ret < LOG_ID_MAX; ++ret) {
    const char* l = LOG_NAME[ret];
    if (l && !strcmp(b, l)) {
      return ret;
    }
  }
  return -1; /* should never happen */
}
