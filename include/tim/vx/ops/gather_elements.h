/****************************************************************************
*
*    Copyright (c) 2022 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/
#ifndef TIM_VX_OPS_GATHER_H_
#define TIM_VX_OPS_GATHER_H_
#include "tim/vx/direct_map_op.h"

namespace tim {
namespace vx {
namespace ops {

/**
 * ## Gather_elements
 *
 * Gather_elements slices from input, **axis** according to **indices**.
 * out[i][j][k] = input[index[i][j][k]][j][k] if axis = 0,
 * out[i][j][k] = input[i][index[i][j][k]][k] if axis = 1,
 * out[i][j][k] = input[i][j][index[i][j][k]] if axis = 2,
 * https://github.com/onnx/onnx/blob/main/docs/Operators.md#GatherElements
 */

class Gather_elements : public DirectMapOp {
 public:
  Gather_elements(Graph* Graph, int axis);

  std::shared_ptr<Operation> Clone(
      std::shared_ptr<Graph>& graph) const override;

 protected:
  int axis_;
};

}  // namespace ops
}  // namespace vx
}  // namespace tim

#endif /* TIM_VX_OPS_GATHER_H_ */