#include "telegram.h"

WiFiClientSecure client_tele;
UniversalTelegramBot bot_tele(bot_token, client_tele);

void set_tele() {
  client_tele.setInsecure();
  client_tele.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  bot_tele.sendMessage(acc_id, "STARTED UP", "");
}

void warning_notify() {

  static bool overload_sent = false;
  static bool overprice_sent = false;

  String warning_msg = "";

  if (power > limit_power && overload_sent == false) {
    overload_sent = true;
    warning_msg += "WARNING OVERLOAD\n";
    warning_msg += "Power : ";
    warning_msg += String(power, 1);
    warning_msg += " W\n\n";
  }

  if (power < limit_power) {
    overload_sent = false;
  }

  if (price > limit_price && overprice_sent == false) {
    overprice_sent = true;
    warning_msg += "WARNING OVERCOST\n";
    warning_msg += "Cost : Rp ";
    warning_msg += String(price, 0);
    warning_msg += "\n\n";
  }

  if (price < limit_price) {
    overprice_sent = false;
  }

  if (warning_msg != "") {
    bot_tele.sendMessage(acc_id, warning_msg, "");
  }
}

void telegram_read() {

  int numNewMessages = bot_tele.getUpdates(bot_tele.last_message_received + 1);

  while (numNewMessages) {

    for (int i = 0; i < numNewMessages; i++) {

      String text = bot_tele.messages[i].text;
      String chat_id = bot_tele.messages[i].chat_id;

      if (text.startsWith("/setpower ")) {

        String value_str = text.substring(10);

        limit_power = value_str.toFloat();

        String msg = "Power limit updated\n";

        msg += "New Limit : ";
        msg += String(limit_power, 1);
        msg += " W";

        bot_tele.sendMessage(chat_id, msg, "");
      }

      else if (text.startsWith("/setprice ")) {

        String value_str = text.substring(10);

        limit_price = value_str.toFloat();

        String msg = "Price limit updated\n";

        msg += "New Limit : Rp ";
        msg += String(limit_price, 0);

        bot_tele.sendMessage(chat_id, msg, "");
      }

      else if (text.startsWith("/setkWhprice ")) {

        String value_str = text.substring(13);

        price_kwh = value_str.toFloat();

        String msg = "Price per kWH updated\n";

        msg += "New Price per kWH : Rp ";
        msg += String(price_kwh, 0);

        bot_tele.sendMessage(chat_id, msg, "");
      }

      else if (text.startsWith("/resetkWh")) {

        pzem.resetEnergy();

        String msg = "Total kWh reseted\n";

        msg += "New Total kWh : ";
        msg += String(energy, 0);

        bot_tele.sendMessage(chat_id, msg, "");
      }

      else if (text == "/help") {

        String msg = "";

        msg += "/setpower VALUE\n";
        msg += "/setprice VALUE\n";
        msg += "/setkWhprice VALUE\n";
        msg += "/resetkWh\n";

        bot_tele.sendMessage(chat_id, msg, "");
        
      } else {
        String msg = "Wrong command, check the command using \"/help\"";
        bot_tele.sendMessage(chat_id, msg, "");
      }
    }
    numNewMessages = bot_tele.getUpdates(bot_tele.last_message_received + 1);
  }
}