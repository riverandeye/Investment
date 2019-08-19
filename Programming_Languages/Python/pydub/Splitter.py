import os
from pydub import AudioSegment as AS


def getAllfilepath(folder):
    res = []
    for name in os.listdir(folder):
        abspath = os.path.join(folder, name)
        if os.path.isdir(abspath):
            res += getAllfilepath(abspath)  # recursive
        else:
            res.append(abspath.replace("\\", '/'))
    return res


def mp3towav(mp3filename):
    # input : absolute path of mp3file
    # output : none (wav file saved)

    if len(mp3filename.split('.')) > 2:
        print("Name format is totally wrong")
        return

    wavfilename = mp3filename.split(".")[0].replace("mp3", "wav") + '.wav'
    AS.from_mp3(mp3filename).export(wavfilename, format="wav")


def split1minute(filePath, fileFormat=None):
    # input : absolute path of file
    # output : none (original files are splitted into 1 minute files)
    one_minute = 60 * 1000

    filename = filePath.split("/")[-1].split(".")[0]
    if fileFormat is None: fileFormat = filePath.split(".")[-1]
    savefolderpath = os.path.join("Music_1min", fileFormat, filename)
    if not os.path.exists(savefolderpath): os.mkdir(savefolderpath)
    original = AS.from_file(filePath, fileFormat)
    print(type(original))

    if(len(original) < one_minute):
        savepath = os.path.join(savefolderpath, filename + '.' + fileFormat).replace("\\", '/')
        print(savepath)
        original.export(savepath, fileFormat)
        return

    for i in range(len(original) // one_minute):
        savepath = os.path.join(savefolderpath, filename + "_" + str(i + 1) + '.' + fileFormat).replace("\\", '/')
        print(savepath)
        if (i + 1) * one_minute > len(original):
            original[i * one_minute:].export(savepath, format=fileFormat)
        else:
            original[i * one_minute: (i + 1) * one_minute].export(savepath, format=fileFormat)


# split all music file into 1 minute
for src in getAllfilepath("Music"):
    split1minute(src)

## change all mp3 file into wav file
# mp3folder = 'Music/mp3'
# for mp3file in os.listdir(mp3folder):
#     filepath = os.path.join(mp3folder, mp3file)
#     mp3Towav(filepath)
