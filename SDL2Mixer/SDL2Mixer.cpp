#include "SDL2Nolibs.h"
#include "SDL2Mixer.h"

CMIXER* CMIXER::sInstance = nullptr;
bool CMIXER::IsInitialized = false;

CMIXER* CMIXER::Instance() {
	if (sInstance == nullptr)
		sInstance = new CMIXER();

	return sInstance;
}

void CMIXER::Release()
{
	/* if anything else needs to be destroyed before this then do it above the instance deleteion */
	delete sInstance;
	sInstance = nullptr;
}

CMIXER::CMIXER() {
	MIXER_LOADED_DLL = LoadLibrary(SDL_MIXER_DLL);
	if (MIXER_LOADED_DLL)
	{
		Mix_Init = (sdl_mixerinit_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_INIT_FUNCTION);
		Mix_Quit = (sdl_quit_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_QUIT_FUNCTION);

		Mix_OpenAudio = (sdl_openaudio_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_OPENAUDIO_FUNCTION);
		Mix_PlayMusic = (sdl_playmusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_PLAYMUSIC_FUNCTION);
		Mix_PlayingMusic = (sdl_playingmusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_PLAYINGMUSIC_FUNCTION);
		Mix_PauseMusic = (sdl_pausemusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_PAUSEMUSIC_FUNCTION);
		Mix_PausedMusic = (sdl_pausedmusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_PAUSEDMUSIC_FUNCTION);
		Mix_ResumeMusic = (sdl_resumemusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_RESUMEMUSIC_FUNCTION);
		Mix_PlayChannelTimed = (sdl_playchanneltimed_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_PLAYCHANNELTIMED_FUNCTION);
		Mix_FreeMusic = (sdl_freemusic_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_FREEMUSIC_FUNCTION);
		Mix_FreeChunk = (sdl_freechunk_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_FREECHUNK_FUNCTION);
		Mix_LoadMUS = (sdl_loadmus_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_LOADMUS_FUNCTION);
		Mix_LoadWAV_RW = (sdl_loadwav_rw_t)GetProcAddress(MIXER_LOADED_DLL, MIXER_LOADWAV_RW_FUNCTION);

		IsInitialized = true;
	}
}

CMIXER::~CMIXER() {
	if (MIXER_LOADED_DLL) {
		FreeLibrary(MIXER_LOADED_DLL);
	}
}


int32_t CMIXER::Init(int32_t flags) {
	return Instance()->Mix_Init(flags);
}

void CMIXER::Quit(void)
{
	Instance()->Mix_Quit();
	return Instance()->Release();
}

const char* CMIXER::GetError(void)
{
	return CSDL::Instance()->GetError();
}

int32_t CMIXER::OpenAudio(int32_t frequency, uint16_t format, int32_t channels, int32_t chunksize) {
	return Instance()->Mix_OpenAudio(frequency, format, channels, chunksize);
}

int32_t CMIXER::PlayMusic(Mix_Music* music, int loops)
{
	return Instance()->Mix_PlayMusic(music, loops);
}

int32_t CMIXER::PlayingMusic(void)
{
	return Instance()->Mix_PlayingMusic();
}

void CMIXER::PauseMusic(void)
{
	return Instance()->Mix_PauseMusic();
}

int32_t CMIXER::PausedMusic(void)
{
	return Instance()->Mix_PausedMusic();
}

void CMIXER::ResumeMusic(void)
{
	return Instance()->Mix_ResumeMusic();
}

int32_t CMIXER::PlayChannelTimed(int32_t channel, Mix_Chunk* chunk, int32_t loops, int32_t ticks)
{
	return Instance()->Mix_PlayChannelTimed(channel, chunk, loops, ticks);
}

int32_t CMIXER::PlayChannel(int32_t channel, Mix_Chunk* chunk, int32_t loops, int32_t ticks)
{
	return Instance()->Mix_PlayChannelTimed(channel, chunk, loops, ticks);
}

void CMIXER::FreeMusic(Mix_Music* music)
{
	return Instance()->Mix_FreeMusic(music);
}

void CMIXER::FreeChunk(Mix_Chunk* chunk)
{
	return Instance()->Mix_FreeChunk(chunk);
}

Mix_Music* CMIXER::LoadMUS(const char* file)
{
	return Instance()->Mix_LoadMUS(file);
}

Mix_Chunk* CMIXER::LoadWAV_RW(SDL_RWops* src, int32_t freesrc)
{
	return Instance()->Mix_LoadWAV_RW(src, freesrc);
}

Mix_Chunk* CMIXER::LoadWAV(const char* file)
{
	return Instance()->Mix_LoadWAV_RW(CSDL::RWFromFile(file, "rb"), 1);
}