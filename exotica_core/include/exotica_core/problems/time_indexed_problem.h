//
// Copyright (c) 2018, University of Edinburgh
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of  nor the names of its contributors may be used to
//    endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef EXOTICA_CORE_TIME_INDEXED_PROBLEM_H_
#define EXOTICA_CORE_TIME_INDEXED_PROBLEM_H_

#include <exotica_core/problems/abstract_time_indexed_problem.h>
#include <exotica_core/time_indexed_problem_initializer.h>

namespace exotica
{
/// \brief Time-indexed problem with bound, joint velocity, and general equality/inequality constraints.
class TimeIndexedProblem : public AbstractTimeIndexedProblem, public Instantiable<TimeIndexedProblemInitializer>
{
public:
    TimeIndexedProblem() = default;
    virtual ~TimeIndexedProblem() = default;

    /// \brief Instantiates the problem from an Initializer
    void Instantiate(TimeIndexedProblemInitializer& init) override;

    /// \brief Evaluates whether the problem is valid, i.e., all bound and general constraints are satisfied.
    bool IsValid() override;

private:
    TimeIndexedProblemInitializer init_;
};
typedef std::shared_ptr<exotica::TimeIndexedProblem> TimeIndexedProblemPtr;
}

#endif  // EXOTICA_CORE_TIME_INDEXED_PROBLEM_H_
