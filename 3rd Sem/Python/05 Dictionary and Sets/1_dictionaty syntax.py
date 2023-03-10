myDict={
    "fast": "in quick manner",
    "harry": "a coder",
    "marks": [1,34,345],
    1: 2
}
# print(myDict['Fast'])
# print(myDict['Marks'])
# myDict['Marks']=[34,34]
# print(myDict['Marks'])
# print(myDict.keys())
# print(myDict.values())
# print(myDict.items())

# update.Dict={
#     "jim": "friend"
# }
# myDict.update(update.Dict)
# print(myDict)

print(myDict.get("harry2"))      # returns none
print(myDict["harry2"])          # throws error