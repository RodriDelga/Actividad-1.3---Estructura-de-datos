#pragma once
#include <Registro.hpp>
#include <OOPUtils.hpp>
#include <string>
#include <vector>
#include <months.hpp>

class FileHandler {
    private:
    MonthRegistry months;
    public:
    void readLogs(std::vector<Registro*> &bitacora, const std::string fileName);
    void storeLogs(std::vector<Registro*> &bitacora, const std::string fileName);
};