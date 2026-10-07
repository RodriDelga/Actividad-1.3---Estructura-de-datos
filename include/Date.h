#pragma once
#include <iostream>

/*
 * Clase Date: representa una fecha con hora (mes, dia, hora, minuto,
 * segundo). Permite compararse cronologicamente con operator<.
 * Matricula: A01648834
 * Matricula: A01648281
 * Matricula: A01645656
 * Matricula: A01648448
 * Fecha: (completar)
 */

struct Date {
    int month;
    int day;
    int hour;
    int minute;
    int second;

    Date(int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0)
        : month(month), day(day), hour(hour), minute(minute), second(second) {
    }

    // Compara cronologicamente esta fecha contra otra.
    // other: la fecha contra la que se compara.
    // Retorna: true si esta fecha es anterior a other.
    bool operator<(const Date &other) const {
        if (month != other.month) return month < other.month;
        else if (day != other.day) return day < other.day;
        else if (hour != other.hour) return hour < other.hour;
        else if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }

     bool operator<=(const Date &other) const {
        if (month != other.month) return month <= other.month;
        else if (day != other.day) return day <= other.day;
        else if (hour != other.hour) return hour <= other.hour;
        else if (minute != other.minute) return minute <= other.minute;
        return second <= other.second;
    }

    void getDate() {
        std::cout << month << " " << day << " " << hour << " " << minute << " " << second;
    }
};