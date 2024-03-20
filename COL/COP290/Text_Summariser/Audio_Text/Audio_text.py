import sys
import whisper
import os


def format_transcript(result):
    transcript = ""
    for segment in result["segments"]:
        start_time = segment["start"]
        end_time = segment["end"]
        text = segment["text"].strip()
        segment_str = f"[{start_time:.2f}, {end_time:.2f}] -> {text}\n"
        transcript += segment_str
    return transcript

def transcribe(filename):
    model = whisper.load_model("base")
    result = model.transcribe(filename, task="transcribe", word_timestamps=True)
    formatted_transcript = format_transcript(result)
    base_filename = os.path.splitext(os.path.basename(filename))[0]
    with open(f"transcribed_{base_filename}.txt", 'w', encoding='utf-8') as f:
        f.write(formatted_transcript)

def main():
    filename = sys.argv[1]
    transcribe(filename)

if __name__ == "__main__":
    main()
