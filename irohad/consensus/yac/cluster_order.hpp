/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_CLUSTER_ORDER_HPP
#define IROHA_CLUSTER_ORDER_HPP

#include <vector>
#include "model/peer.hpp"

namespace iroha {
  namespace consensus {
    namespace yac {

      /**
       * Class provide ordering on cluster for current round
       */
      class ClusterOrdering {
       public:

        explicit ClusterOrdering(std::vector<model::Peer> order);

        /**
         * Provide current leader peer
         */
        model::Peer currentLeader();

        /**
         * Switch to next peer as leader
         * @return this
         */
        ClusterOrdering &switchToNext();

        /**
         * @return true if current leader not last peer in order
         */
        bool hasNext();

        std::vector<model::Peer> getPeers() { return order_; };

        auto getNumberOfPeers() { return order_.size(); }

        virtual ~ClusterOrdering() = default;

       private:
        std::vector<model::Peer> order_;
        uint32_t index_ = 0;
      };
    }  // namespace yac
  }    // namespace consensus
}  // namespace iroha
#endif  // IROHA_CLUSTER_ORDER_HPP
