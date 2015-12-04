// http://careercup.com/question?id=5685801251766272

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long INT64;

INT64 getDiff(string startTime, string endTime) {
	string command = "date +%s -d ";
	char cmd[256];
	char buf[256];
	FILE *ptr;
	INT64 start, end;
	int i;

	startTime = command + "'" + startTime + "'";
	strcpy(cmd, startTime.c_str());
	if ((ptr = popen(cmd, "r")) != NULL) {
		while (fgets(buf, 256, ptr) != NULL) {
			start = 0;
			i = 0;
			while (buf[i] >= '0' && buf[i] <= '9') {
				start = start * 10 + (buf[i] - '0');
				i++;
			}
		}

		fclose(ptr);
	}
	
	endTime = command + "'" + endTime + "'";
	strcpy(cmd, endTime.c_str());
	if ((ptr = popen(cmd, "r")) != NULL) {
		while (fgets(buf, 256, ptr) != NULL) {
			end = 0;
			i = 0;
			while (buf[i] >= '0' && buf[i] <= '9') {
				end = end * 10 + (buf[i] - '0');
				i++;
			}
		}

		fclose(ptr);
	}

	return end - start;
}

void findHighestTimeDifference(string filename) {
	ifstream inFile(filename.c_str());
	string startTime, endTime, maxStartTime, maxEndTime;
	INT64 diff, maxDiff;
	char buffer[256];
	int i;

    while(!inFile.eof()){
            inFile.getline(buffer, 100);
			string str(buffer);
			if (str.substr(0, 10).compare("STARTTIME:") == 0) {
				startTime = str.substr(10, str.size() - 10);
			} else if (str.substr(0, 9).compare("ENDTIME :") == 0) {
				endTime = str.substr(9, str.size() - 9);
				diff = getDiff(startTime, endTime);

				if (maxStartTime.size() == 0 || maxDiff < diff) {
				    maxStartTime = startTime;
				    maxEndTime = endTime;
				    maxDiff = diff;
				}
			}
    }
    inFile.close();
    
    cout << "STARTTIME:" << maxStartTime << "\n";
    cout << "ENDTIME :" << maxEndTime << "\n";
}

int main()
{
	findHighestTimeDifference("time.log");

	return 0;
}

/*
STARTTIME:2015-12-01 04:13:15
ENDTIME :2015-12-01 04:14:16
----------------------------------------------
----------------------------------------------
STARTTIME:2015-12-01 04:11:15
ENDTIME :2015-12-01 04:11:17
----------------------------------------------
----------------------------------------------
STARTTIME:2015-12-01 04:12:15
ENDTIME :2015-12-01 04:15:15
----------------------------------------------
----------------------------------------------
STARTTIME:2015-12-01 04:10:10
ENDTIME :2015-12-01 04:10:11
----------------------------------------------
----------------------------------------------
*/
