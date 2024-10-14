#pragma once
#include "linkedStack.h"
#include "announcement.h"

class AnnouncementListType : public LinkedStackType<Announcement> {
public:
	AnnouncementListType();

	/**
	* @title in announcements.dat
	*/
	Announcement* search(string title);

private:

};
