/*
 * definitions.h
 *
 *  Created on: Sep 1, 2014
 *      Author: kevin
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdint.h>
#include "hash.h"
#include "list.h"

#define MAX 1024


typedef struct Person {
	char name[256];
	uint32_t isEmployee;
	uint32_t roomID;
	uint32_t enterTime;
	uint32_t leaveTime;
	Node * rooms;
} person;

typedef struct {
	char * token;
	uint32_t inHTML;
	uint32_t currentState;
	uint32_t totalTime;
	uint32_t listAllRooms_R;
	uint32_t printSpecificRooms_I;
	uint32_t listEmployeesWithTime;
	uint32_t listEmployeesWithoutTime;
	char * employeeName;
	char * guestName;
	int32_t lowerBound;
	int32_t upperBound;
	char * logName;

} logread_args;

typedef struct {
	/*
	 *   Positive number of seconds since gallery opened.  Time should always increase.
	 *   Invoking logappend with event prior to time of most recent log is an error
	 */
	int32_t timestamp;
	/*
	 *	Token used to authenticate log.  Consists of arbitrary-sized string of alphanumeric (a-aA-Z0-9) characters.
	 *	Once a log is created, subsequent logs must use same token.
	 */
	char * token;
	/*
	 * Upper and lower case letters only.  No spaces.  This applies to both guestName and employeeName which are mutually exclusive.
	 */
	char * employeeName;
	char * guestName;
	/*
	 * Can be used with the name options as well as the room ID options.  In no room ID is defined, assume -A
	 * means that they arrived at the gallery as a whole. Should never enter a room without having left the last room they entered.
	 */
	int32_t eventArrival;
	/*
	 * Can be used with the name options as well as the room ID options.  In no room ID is defined, assume -L
	 * means that they left the building. Cannot leave the gallery without last leaving the room they entered.
	 */
	int32_t eventDeparture;
	/*
	 * None-negative integer characters with no spaces.  A
	 */
	int32_t roomID;
	/*
	 * Path to file containing log
	 */
	char * logName;
	/*
	 * Path to file containing list of commands to run
	 */
	char * batchFile;

	int returnStatus;

	//String representation
	char * toString;

} logappend_args;

#endif /* DEFINITIONS_H_ */
