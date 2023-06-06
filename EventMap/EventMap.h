#pragma once
#include<vector>

#define MAX_MAP_LIST 100 // 최대 이벤트 맵 생성 개수

namespace PlayerRole { // 이벤트 참가자들의 역할
	enum Type {
		NONE,
		NORMAL, // 일반 참가자
		LEADER  // 파티장
		// 향후 파티의 규모가 증가되거나 컨셉에 따라 더 추가될수도있다 . . . .
	};
};

namespace EventKind {
	enum Type {
		NONE,
		EVENT1,
		EVENT2
		// 추가하려는 이벤트맵의 종류를 여기에 . . . .
	};
}

class EventPlayer {
	// 이벤트 맵에 참가하는 사람
public:
	EventPlayer();
	~EventPlayer();

public:
	int playerID; // 참가자의 ID, 이 ID를 가지고 검색해서 정보를 얻어낸다.
	PlayerRole::Type role; // 참가자들의 이벤트 역할

	bool isReady; // 이벤트 맵에 참가할 준비가 됐는지
	bool isTry; // 이벤트 맵을 플레이(공략)중인지
	std::vector<int> idEntry; // 파티장만 가질수있는 엔트리, 참가자들의 id가 적혀있다.

public:
	void Initialize(int id, PlayerRole::Type role); // 초기화
	void ApplyToEventMap(); // EventMapManager에게 이벤트 맵 참가 신청을 한다.

	
};

class EventMapBase {

public:
	EventMapBase();
	~EventMapBase();

public:
	std::vector<EventPlayer> playerEntry; // 이벤트 맵에 참가하는 사람들


public:
	void Initialize();

};

class EventMapManager {

public:
	EventMapManager();
	~EventMapManager();

public:
	std::vector<EventMapBase> eventMapBase; // 매니저가 관리하는 맵

public:
	void Initialize();
	void EnrollmentApplicant();
};

