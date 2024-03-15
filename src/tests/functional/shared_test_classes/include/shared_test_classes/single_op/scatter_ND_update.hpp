// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "shared_test_classes/base/ov_subgraph.hpp"

namespace ov {
namespace test {
using scatterNDUpdateSpecParams = std::tuple<
        std::vector<InputShape>,           // input, update shapes
        ov::Shape,                         // indices shape
        std::vector<size_t>                // indices value
>;

using scatterNDUpdateParamsTuple = typename std::tuple<
        scatterNDUpdateSpecParams,
        ov::element::Type,                 // Model type
        ov::element::Type,                 // Indices type
        ov::test::TargetDevice             // Device name
>;

class ScatterNDUpdateLayerTest : public testing::WithParamInterface<scatterNDUpdateParamsTuple>,
                                 virtual public ov::test::SubgraphBaseTest {
public:
    static std::string getTestCaseName(const testing::TestParamInfo<scatterNDUpdateParamsTuple> &obj);

protected:
    void SetUp() override;
};
}  // namespace test
}  // namespace ov
