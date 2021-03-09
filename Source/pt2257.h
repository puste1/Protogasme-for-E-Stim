#include <Arduino.h>

#ifndef pt2257_h
#define pt2257_h
//----------------------------------------------------------
class PT2257 {
  public:
    PT2257();
    void init();
    void set_volume(uint8_t db);
    void set_volume_left(uint8_t db);
    void set_volume_right(uint8_t db);
    void mute(bool st);
    void off();
  private:
};
//----------------------------------------------------------
#endif
