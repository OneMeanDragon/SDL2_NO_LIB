#if !defined(SDL_MIXERDLL_H)
#define SDL_MIXERDLL_H
#pragma once

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <libloaderapi.h>
#include <cinttypes>
#include <SDL_mixer.h>


#define SDL_MIXER_DLL TEXT("SDL2_MIXER.DLL")

#define MIXER_INIT_FUNCTION "Mix_Init"
#define MIXER_QUIT_FUNCTION "Mix_Quit"

#define MIXER_OPENAUDIO_FUNCTION "Mix_OpenAudio"
#define MIXER_PLAYMUSIC_FUNCTION "Mix_PlayMusic"
#define MIXER_PLAYINGMUSIC_FUNCTION "Mix_PlayingMusic"
#define MIXER_PAUSEMUSIC_FUNCTION "Mix_PauseMusic"
#define MIXER_PAUSEDMUSIC_FUNCTION "Mix_PausedMusic"
#define MIXER_RESUMEMUSIC_FUNCTION "Mix_ResumeMusic"
#define MIXER_PLAYCHANNELTIMED_FUNCTION "Mix_PlayChannelTimed"
#define MIXER_FREEMUSIC_FUNCTION "Mix_FreeMusic"
#define MIXER_FREECHUNK_FUNCTION "Mix_FreeChunk"
#define MIXER_LOADMUS_FUNCTION "Mix_LoadMUS"
#define MIXER_LOADWAV_RW_FUNCTION "Mix_LoadWAV_RW"

/*
extern DECLSPEC Mix_Chunk * SDLCALL Mix_LoadWAV_RW(SDL_RWops *src, int freesrc);
*/
typedef int32_t(*sdl_mixerinit_t)(int32_t flags);
typedef void(*sdl_quit_t)(void);

typedef int32_t(*sdl_openaudio_t)(int32_t frequency, uint16_t format, int32_t channels, int32_t chunksize);
typedef int32_t(*sdl_playmusic_t)(Mix_Music* music, int32_t loops);
typedef int32_t(*sdl_playingmusic_t)(void);
typedef void(*sdl_pausemusic_t)(void);
typedef int32_t(*sdl_pausedmusic_t)(void);
typedef void(*sdl_resumemusic_t)(void);
typedef int32_t(*sdl_playchanneltimed_t)(int32_t channel, Mix_Chunk* chunk, int32_t loops, int32_t ticks);
typedef void(*sdl_freemusic_t)(Mix_Music* music);
typedef void(*sdl_freechunk_t)(Mix_Chunk* chunk);
typedef Mix_Music* (*sdl_loadmus_t)(const char* file);
typedef Mix_Chunk* (*sdl_loadwav_rw_t)(SDL_RWops* src, int32_t freesrc);

class CMIXER {
private:
	static CMIXER* sInstance;
#if defined(SDL_MUTEX)
	static std::mutex mutex_;
#endif
private:

	CMIXER();
	~CMIXER();

public:
	CMIXER(const CMIXER& obj) = delete;     /* Remove the copy constructor */
	void operator=(const CMIXER&) = delete; /* Remove the assignment operator */
public:
	static bool IsInitialized;

	static CMIXER* Instance();
	static void Release();

	static int32_t Init(int32_t flags);
	static void Quit(void);
	static const char* GetError(void);

	static int32_t OpenAudio(int32_t frequency, uint16_t format, int32_t channels, int32_t chunksize);
	static int32_t PlayMusic(Mix_Music* music, int32_t loops);
	static int32_t PlayingMusic(void);
	static void PauseMusic(void);
	static int32_t PausedMusic(void);
	static void ResumeMusic(void);
	static int32_t PlayChannelTimed(int32_t channel, Mix_Chunk* chunk, int32_t loops, int32_t ticks);
	static int32_t PlayChannel(int32_t channel, Mix_Chunk* chunk, int32_t loops, int32_t ticks = -1);
	static void FreeMusic(Mix_Music* music);
	static void FreeChunk(Mix_Chunk* chunk);
	static Mix_Music* LoadMUS(const char* file);
	static Mix_Chunk* LoadWAV_RW(SDL_RWops* src, int32_t freesrc);
	static Mix_Chunk* LoadWAV(const char* file);

private:
	sdl_mixerinit_t Mix_Init = nullptr;
	sdl_quit_t Mix_Quit = nullptr;

	sdl_openaudio_t Mix_OpenAudio = nullptr;
	sdl_playmusic_t Mix_PlayMusic = nullptr;
	sdl_playingmusic_t Mix_PlayingMusic = nullptr;
	sdl_pausemusic_t Mix_PauseMusic = nullptr;
	sdl_pausedmusic_t Mix_PausedMusic = nullptr;
	sdl_resumemusic_t Mix_ResumeMusic = nullptr;
	sdl_playchanneltimed_t Mix_PlayChannelTimed = nullptr;
	sdl_freemusic_t Mix_FreeMusic = nullptr;
	sdl_freechunk_t Mix_FreeChunk = nullptr;
	sdl_loadmus_t Mix_LoadMUS = nullptr;
	sdl_loadwav_rw_t Mix_LoadWAV_RW = nullptr;

private:
	HINSTANCE MIXER_LOADED_DLL;
};



#endif
