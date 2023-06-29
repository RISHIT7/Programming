import discord

TOKEN='MTA2Mzg2NTM2NDk2ODEyMDM3MA.GFMAqm.2rMwLRIvTdictIZCML5c2_rpoLr9V3AtRqIYuE'

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

client.run(TOKEN)