import discord

client = discord.Client()

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
    if message.author == client.user:
        return
    
    if message.content.startswith('$hello'):
        await message.channel.send('Hello!')

client.run('MTA2Mzg0ODUzODk2ODE2NjU2NA.GxUQE7.yKg3y0HNmOacz8z-vBzIUzysCRBNmCa-6OTMZc')