#include <iostream>
#include <string>
#include "discussion.h"
#include "discussionListType.h"
#include "linkedListIterator.h"

using namespace std;

DiscussionListType::DiscussionListType() {
	// TODO...
}

Discussion* DiscussionListType::search(string fullname) {	
	Student s(fullname);
	Discussion d;
	d.setStudent(s);
	LinkedListIterator<Discussion> it;
	for (it = begin(); it != end(); ++it) {
		if (d == *it) {
			break;
		}
	}
	return &(*it);
}