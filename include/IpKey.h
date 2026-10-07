/*
 * Description: Represents an IPv4 key used for comparisons and lookups.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include <vector>
#include <string>
#include <array>

struct IpKey {
	std::array<int, 4> ipKey = {0, 0, 0, 0};

	IpKey(int w, int x, int y, int z) {
		ipKey[0] = w;
		ipKey[1] = x;
		ipKey[2] = y;
		ipKey[3] = z;
	}
	
	IpKey() {}
	
	IpKey(std::array<int, 4> newIpKey) {
		ipKey = newIpKey;
	}
	
	IpKey(std::vector<std::string>& ipKeys) {
		for (int i = 0; i < 4; i++) {
			ipKey[i] = std::stoi(ipKeys[i]);
		}
	}

	// Purpose: Retrieves an individual octet from the IP key.
	// Parameters: i - index of the octet to retrieve (0 to 3).
	// Return value: The integer value of the octet.
	int getIpKey(int i) const {
		return ipKey[i];
	}

	// Purpose: Evaluates if the current IP Key is strictly less than another IP Key.
	// Parameters: otherRegistro - the other IP Key to compare against.
	// Return value: True if the current IP Key is less than the other.
	bool operator<(const IpKey &otherRegistro) const {
		if (ipKey[0] != otherRegistro.getIpKey(0)) {
			return ipKey[0] < otherRegistro.getIpKey(0);
		} else if (ipKey[1] != otherRegistro.getIpKey(1)) {
			return ipKey[1] < otherRegistro.getIpKey(1);
		} else if (ipKey[2] != otherRegistro.getIpKey(2)) {
			return ipKey[2] < otherRegistro.getIpKey(2);
		} else if (ipKey[3] != otherRegistro.getIpKey(3)) {
			return ipKey[3] < otherRegistro.getIpKey(3);
		} else {
			return false;
		}
	}

	// Purpose: Evaluates if the current IP Key is less than or equal to another IP Key.
	// Parameters: otherRegistro - the other IP Key to compare against.
	// Return value: True if the current IP Key is less than or equal to the other.
	bool operator<=(const IpKey &otherRegistro) const {
		if (ipKey[0] != otherRegistro.getIpKey(0)) {
			return ipKey[0] <= otherRegistro.getIpKey(0);
		} else if (ipKey[1] != otherRegistro.getIpKey(1)) {
			return ipKey[1] <= otherRegistro.getIpKey(1);
		} else if (ipKey[2] != otherRegistro.getIpKey(2)) {
			return ipKey[2] <= otherRegistro.getIpKey(2);
		} else if (ipKey[3] != otherRegistro.getIpKey(3)) {
			return ipKey[3] <= otherRegistro.getIpKey(3);
		}
		
		return true;
	}
};