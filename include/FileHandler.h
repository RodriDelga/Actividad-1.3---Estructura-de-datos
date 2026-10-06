#pragma once
#include "Registro.h"
#include "OOPUtils.h"
#include <string>
#include <vector>
#include "Months.h"

class FileHandler {
    private:
    MonthRegistry months;
    public:
    void readLogs(std::vector<Registro*> &bitacora, const std::string fileName);
    void storeLogs(std::vector<Registro*> &bitacora, const std::string fileName);
};