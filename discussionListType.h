#pragma once
#include "unorderedLinkedList.h"
#include "discussion.h"

class DiscussionListType : public UnorderedLinkedList<Discussion> {
public:
	DiscussionListType();

	/**
	* @fullname - first middle last as in discussions.dat
	*/
	Discussion* search(string fullname);

private:

};
