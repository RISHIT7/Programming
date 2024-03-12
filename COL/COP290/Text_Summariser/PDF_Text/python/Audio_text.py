import sys
import whisper

def transcribe(filename):
    model = whisper.load_model("base")
    result = model.transcribe(filename)

    with open(f"transcripted_{filename}.txt", 'w') as f:
        f.write(result["text"])

def main():
    filename = sys.argv[2]
    transcribe(filename)

if __name__ == "__main__":
    main()