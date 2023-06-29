import telebot

bot = telebot.TeleBot("5667069480:AAHSHWJH2pR4qeUxfXEHb3yQXX1mtF4odUo")

@bot.message_handler(commands=['Greet'])
def greet(message):
    bot.reply_to(message, "Hey! Hows it going?")

@bot.message_handler(commands=['hello'])
def hello(message):
    bot.send_message(message.chat.id, "hello")



bot.polling()