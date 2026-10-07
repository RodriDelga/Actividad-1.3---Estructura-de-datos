#pragma once
#include <vector>

struct IpKey {
    std::array<int, 4> ipKey = {0,0,0,0};

    IpKey(int w, int x, int y, int z){
        ipKey[0] = w;
        ipKey[1] = x;
        ipKey[2] = y;
        ipKey[3] = z;
    }
    IpKey() {}
    IpKey(std::array<int, 4> ipKey_) {
        ipKey=ipKey_;
    }
    IpKey(std::vector<std::string>& ipKeys) {
        for (int i = 0; i < 4; i++) {
        ipKey[i] = std::stoi(ipKeys[i]);
    }
    } 

    int getIpKey(int i) const {
        return ipKey[i];
    }

    bool operator<(const IpKey &otherRegistro) const  {
    if(ipKey[0] != otherRegistro.getIpKey(0)) {
        return ipKey[0] < otherRegistro.getIpKey(0);
    }
    else if(ipKey[1] != otherRegistro.getIpKey(1)) {
        return ipKey[1] < otherRegistro.getIpKey(1);
    }
    else if(ipKey[2] != otherRegistro.getIpKey(2)) {
        return ipKey[2] < otherRegistro.getIpKey(2);
    }
    else if(ipKey[3] != otherRegistro.getIpKey(3)) {
        return ipKey[3] < otherRegistro.getIpKey(3);
    }
    else return false;

}

bool operator<=(const IpKey &otherRegistro) const  {
    if(ipKey[0] != otherRegistro.getIpKey(0)) {
        return ipKey[0] <= otherRegistro.getIpKey(0);
    }
    else if(ipKey[1] != otherRegistro.getIpKey(1)) {
        return ipKey[1] <= otherRegistro.getIpKey(1);
    }
    else if(ipKey[2] != otherRegistro.getIpKey(2)) {
        return ipKey[2] <= otherRegistro.getIpKey(2);
    }
    else if(ipKey[3] != otherRegistro.getIpKey(3)) {
        return ipKey[3] <= otherRegistro.getIpKey(3);
    }
    return true;
}
};