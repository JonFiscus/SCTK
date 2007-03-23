/*
 * asclite
 * Author: Jerome Ajot, Nicolas Radde, Chris Laprun
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

#ifndef SPEECH_H
#define SPEECH_H

#include "stdinc.h"
#include "segment.h"

class SpeechSet;

/**
 * Internal representation of an hypothesis file or a reference file.
 */
class Speech
{
	public:
		// class constructor
		Speech(SpeechSet* parentSet);
		Speech(const vector<Segment *>& segments);
		
		// class destructor
		virtual ~Speech();
		/**
		 * Retrieve the segment indexed by index.
		 */
		Segment* GetSegment(size_t index) { return m_segments[index]; }
		/**
		 * Add this segment at the end of the segment list.
		 */
		virtual void AddSegment(Segment* segment) { m_segments.push_back(segment); }
		/**
		 * Return the number of Segments inside the Speech
		 */
		size_t NbOfSegments() { return m_segments.size(); }
		/**
		 * Return the next Segment starting at the specified time for
		 * the specified source and channel. If the time is in the middle of
		 * A segment return the segment itself.
		 */
		Segment* NextSegment(int time, string source, string channel);
		/**
		 * Return the segments of this speech by the given time
		 */
		vector<Segment*> GetSegmentsByTime(int start, int end, string source, string channel);
		/** Determines if case is taken into account to align Tokens part of this Speech. */
		bool PerformCaseSensitiveAlignment();
		/** Determines if fragments are considered as correct when aligning Tokens part of this Speech. */
		bool AreFragmentsCorrect();
		/** Determines if optionally deletable Tokens need to be accounted for. */
		bool UseOptionallyDeletable();
		/** Retrieves the SpeechSet in which this Speech is located */
		SpeechSet* GetParentSpeechSet();
		/** returns the Speech as a string */
		string ToString();
	private:
		Speech();
		/**
		 * Represent all the segments of this speech.
		 * Note : By definition they cannot overlap with each other
		 */
		vector<Segment*> m_segments;		
		/**
		 * The parent Set that contain the speech
		 */
		SpeechSet* parentSet;
};

#endif // SPEECH_H