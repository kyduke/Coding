### LGE Code Jam 2016 2nd Problem 2

# Intersection

메인 도로와 하나의 가지만을 가지는 도로가 있다. 각 도로는 도시들을 연결하고, 각 도시에서 기름을 넣을 수 있다. 기름 값은 각 도시마다 다르며 넣을 수 있는 양은 제한이 없다.
가지가 없고 두개의 도시가 있는 경우 출발 도시에서 도착 도시까지 거리만큼만 주유하면 된다.
가지를 들러서 주유하는 경우가 더 비용이 저렴하면 그 방법을 선택할 수 있다.

입력)
첫 줄에는 테스트 케이스의 수 T가 주어진다. 1 <= T <= 135

각 케이스의 첫 줄에는 주 도로의 도시 수 N이 주어진다. 1 <= ㅜN <= 5000
다음 줄에는 N - 1 쌍으로 기름 값과 다음 도시까지의 거리가 주어진다.
다음 줄에는 교차로가 있는 도시 K와 가지 도로에 있는 도시의 수 M이 주어진다. 1 <= K <= N, 1 <= M <= 5000
다음 줄에는 M 쌍으로 이전 도시와의 거리와 기름 값이 주어진다.

출력)
각 테스트 케이스의 최소 비용을 출력한다.
