# ProtoHUD

Arduino-based heads-up display for protogens

----// DISCLAIMER //----

I am not claiming original ownership of any of this code. All references to outside sources are cited in the comments of the main file.

----// Description //----

Basically, this is a piece of code for a heads-up display, to be used in a protogen helm. I want to have some additional data
about the environment that is visible from inside the helmet, such as temperature/ humidity, and the current time.
This code should be fairly lightweight and modular, but will likely end up being ESP32-specific for however I implement
the time-query function.

----// TODO //----

* configTime should be able to poll time from an NTP server

//configTime(timezone * 3600, dst * 0, "pool.ntp.org","time.nist.gov");
//time_t now = time(nullptr);
//display.println(ctime(&now));


* figure out which method to use for internet connection. Connect ESP32 to phone hotspot, bluetooth, or be extra and give it a SIM card?
