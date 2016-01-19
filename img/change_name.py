
import os

allFileNames = os.listdir(".");
count = 0;
for fileName in allFileNames:
	if fileName[-1] == 'g':
		count += 1;
		newFileName = "./n"+str(count)+".jpg";
		os.rename("./"+fileName, newFileName);

print count;