/*
 *  Copyright (c) 2015-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <thrift/lib/cpp/util/ScopedServerThread.h>

namespace folly {
  class EventBase;
}

namespace facebook { namespace bistro {

namespace cpp2 {
  class BistroSchedulerAsyncClient;
  class ServiceAddress;
}

class ThriftMonitor;

/**
 * Running BistroScheduler service on threads for testing
 */
class ThriftMonitorTestThread {
public:
  ThriftMonitorTestThread();

  std::shared_ptr<cpp2::BistroSchedulerAsyncClient> getClient(
    folly::EventBase* event_base
  );

  cpp2::ServiceAddress getAddress() const;

private:
  apache::thrift::util::ScopedServerThread sst_;
  std::shared_ptr<ThriftMonitor> monitorPtr_;
};

}}
