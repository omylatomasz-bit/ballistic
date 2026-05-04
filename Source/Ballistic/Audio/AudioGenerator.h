#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioGenerator.generated.h"

UENUM(BlueprintType)
enum class EAudioType : uint8
{
\tBackgroundMusic UMETA(DisplayName = "Background Music"),
\tSoundEffect UMETA(DisplayName = "Sound Effect"),
\tVoiceLine UMETA(DisplayName = "Voice Line"),
\tAmbianceSound UMETA(DisplayName = "Ambiance Sound")
};

UCLASS(Blueprintable, BlueprintType)
class BALLISTIC_API AAudioGenerator : public AActor
{
\tGENERATED_BODY()

public:
\tAAudioGenerator();

\tvirtual void BeginPlay() override;
\tvirtual void Tick(float DeltaTime) override;

\t// Audio Generation Methods
\tUFUNCTION(BlueprintCallable, Category = "Audio Generation")
\tvoid GenerateBackgroundMusic(const FString& MusicTheme, float Duration);

\tUFUNCTION(BlueprintCallable, Category = "Audio Generation")
\tvoid GenerateSoundEffect(const FString& EffectType, float Intensity);

\tUFUNCTION(BlueprintCallable, Category = "Audio Generation")
\tvoid GenerateVoiceLine(const FString& VoiceText, const FString& VoiceActor);

\tUFUNCTION(BlueprintCallable, Category = "Audio Generation")
\tvoid GenerateAmbianceSound(const FString& AmbianceType, float Duration);

\t// Audio Playback Methods
\tUFUNCTION(BlueprintCallable, Category = "Audio Playback")
\tvoid PlayAudio(const FString& AudioFilePath);

\tUFUNCTION(BlueprintCallable, Category = "Audio Playback")
\tvoid StopAudio();

\tUFUNCTION(BlueprintCallable, Category = "Audio Playback")
\tvoid PauseAudio();

\tUFUNCTION(BlueprintCallable, Category = "Audio Playback")
\tvoid ResumeAudio();

\tUFUNCTION(BlueprintCallable, Category = "Audio Playback")
\tvoid SetVolume(float NewVolume);

protected:
\tUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Settings")
\tfloat MasterVolume;

\tUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Settings")
\tbIsPlaying;

\tUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "API Settings")
\tFString OpenAIAPIKey;

\tUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "API Settings")
\tFString ElevenLabsAPIKey;

private:
\tclass UAudioComponent* CurrentAudioComponent;
\tFString CurrentAudioPath;
};
