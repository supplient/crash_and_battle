#include "animal.h"

bool animal::setLeader(animal * p)
{
	if (leader)
		return false;
	leader = p;
	return true;
}

bool animal::removeFollower(animal * p)
{
	for (vector<animal*>::iterator i = follower.begin(); i != follower.end(); i++)
		if (*i == p)
		{
			follower.erase(i);
			return true;
		}
			
	return false;
}
