// http://www.careercup.com/question?id=5701939272613888

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
	int maxPoint;
	int pointsPerMinute;
	int requiredTime;
	int visit;
	Task() {
		maxPoint = 0;
		pointsPerMinute = 0;
		requiredTime = 0;
		visit = 0;
	}
};

void processInput(int& totalTime, vector<Task>& tasks) {
	string buffer;
	int taskIndex, i, t;

	cin >> totalTime;

	cin >> buffer;
	i = 0;
	t = 0;
	while (i <= (int)buffer.size()) {
		if (i == buffer.size() || buffer[i] == ',') {
			Task task;
			task.maxPoint = t;
			tasks.push_back(task);
			t = 0;
		} else {
			t = t * 10 + (buffer[i] - '0');
		}
		i++;
	}

	cin >> buffer;
	taskIndex = 0;
	i = 0;
	t = 0;
	while (i <= (int)buffer.size()) {
		if (i == buffer.size() || buffer[i] == ',') {
			tasks[taskIndex].pointsPerMinute = t;
			taskIndex++;
			t = 0;
		} else {
			t = t * 10 + (buffer[i] - '0');
		}
		i++;
	}

	cin >> buffer;
	taskIndex = 0;
	i = 0;
	t = 0;
	while (i <= (int)buffer.size()) {
		if (i == buffer.size() || buffer[i] == ',') {
			tasks[taskIndex].requiredTime = t;
			taskIndex++;
			t = 0;
		} else {
			t = t * 10 + (buffer[i] - '0');
		}
		i++;
	}
}

int solve(int totalTime, vector<Task>& tasks, int time) {
	int ret, i, point;

	if (time >= totalTime) return 0;

	ret = 0;
	for (i = 0; i < (int)tasks.size(); i++) {
		if (tasks[i].visit == 1) continue;
		tasks[i].visit = 1;
		point = tasks[i].maxPoint - (time + tasks[i].requiredTime) * tasks[i].pointsPerMinute;
		ret = max(ret, point + solve(totalTime, tasks, time + tasks[i].requiredTime));
		tasks[i].visit = 0;
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<Task> tasks;
	int totalTime;

	processInput(totalTime, tasks);
	
	cout << solve(totalTime, tasks, 0) << "\n";

	return 0;
}

/*
75
250,500,1000
2,4,8
25,25,25
=====
1200
*/
