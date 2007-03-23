/*
 * asclite
 * Author: Ajot Jerome, Radde Nicolas, Laprun Chris
 *
 * This software was developed at the National Institute of Standards and Technology by
 * employees of the Federal Government in the course of their official duties.  Pursuant to
 * Title 17 Section 105 of the United States Code this software is not subject to copyright
 * protection within the United States and is in the public domain. asclite is
 * an experimental system.  NIST assumes no responsibility whatsoever for its use by any party.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS."  With regard to this software, NIST MAKES NO EXPRESS
 * OR IMPLIED WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef ALIGNMENT_TEST_H
#define ALIGNMENT_TEST_H

#include "stdinc.h"
#include "alignment.h"
#include "segmentsgroup.h"
#include "std_benchmark.h"

class AlignmentTest {
public:
	AlignmentTest();
	~AlignmentTest();

	void TestAll();
	void TestInsertions();	
	void TestDeletions();		
	
private:
	StdBenchmark* bench;
	
	Alignment* GetAlignmentFor(int testIndex, SegmentsGroup** sg);
};

#endif
