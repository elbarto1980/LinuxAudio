// https://www.linuxjournal.com/article/6735
// https://github.com/mtk-jin/Alsa-Demo.git

#include <alsa/asoundlib.h>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

static int EnumDevices() {
  void **hints;

  std::cout << "Available ALSA PCM devices:" << std::endl;
  if (snd_device_name_hint(-1, "pcm", &hints) < 0)
    return -1;

  int n = 0;

  for (size_t i = 0; hints[i] != nullptr; i++) {
    const void *hint = hints[i];

    std::string name{snd_device_name_get_hint(hint, "NAME")};
    std::string desc{snd_device_name_get_hint(hint, "DESC")};
    boost::replace_all(desc, "\n", ", ");

    std::cout << name << " <=///=> " << desc << std::endl << std::endl;
    n++;
  }

  snd_device_name_free_hint(hints);
  return n;
}

int main() {
  int val;

  printf("ALSA library version: %s\n", SND_LIB_VERSION_STR);

  printf("\nPCM stream types:\n");
  for (val = 0; val <= SND_PCM_STREAM_LAST; val++)
    printf("  %s\n", snd_pcm_stream_name((snd_pcm_stream_t)val));

  printf("\nPCM access types:\n");
  for (val = 0; val <= SND_PCM_ACCESS_LAST; val++)
    printf("  %s\n", snd_pcm_access_name((snd_pcm_access_t)val));

  printf("\nPCM formats:\n");
  for (val = 0; val <= SND_PCM_FORMAT_LAST; val++)
    if (snd_pcm_format_name((snd_pcm_format_t)val) != nullptr)
      printf("  %s (%s)\n", snd_pcm_format_name((snd_pcm_format_t)val),
             snd_pcm_format_description((snd_pcm_format_t)val));

  printf("\nPCM subformats:\n");
  for (val = 0; val <= SND_PCM_SUBFORMAT_LAST; val++)
    printf("  %s (%s)\n", snd_pcm_subformat_name((snd_pcm_subformat_t)val),
           snd_pcm_subformat_description((snd_pcm_subformat_t)val));

  printf("\nPCM states:\n");
  for (val = 0; val <= SND_PCM_STATE_LAST; val++)
    printf("  %s\n", snd_pcm_state_name((snd_pcm_state_t)val));

  std::cout << "\n\n";
  std::cout << EnumDevices() << " devices found." << std::endl << std::endl;

  return 0;
}