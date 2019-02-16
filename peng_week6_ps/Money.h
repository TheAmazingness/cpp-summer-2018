/*
 * PS6
 * Money.h
 * Tristan Peng
 * CLion
 */
#pragma once

class Money
{
  private:
    unsigned int dollars, cents;
    bool negative;
  public:
    Money();
    Money(unsigned int d, unsigned int c = 0);
    Money(double m);
    Money(const Money &m);
    ~Money();
    void setMoney(unsigned int d, unsigned int c);
    void setMoney(double m);
    void increase(unsigned int d, unsigned int c);
    void decrease(unsigned int d, unsigned int c);
    void show() const;
};