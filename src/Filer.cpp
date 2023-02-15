#include "Filer.h"

namespace glow
{
#ifdef DATA_DIR
  std::filesystem::path data_directory(DATA_DIR);
#else
  std::filesystem::path data_directory;
#endif

  const std::string palettes = "palettes";
  const std::string frames = "frames";
  const std::string layers = "layers";
  const std::string chromas = "chromas";
  const std::string grids = "grids";

  const std::string symbols = "symbols";
  const std::string derived = "derived";

  const std::string palette_name = "palette.yaml";
  const std::string frame_name = "frame.yaml";
  const std::string frame_symbolic = "frame_symbolic.yaml";
  const std::string layer_name = "layer.yaml";
  const std::string layer_symbolic = "layer_symbolic.yaml";
  const std::string grid_name = "grid.yaml";
  const std::string grid_symbolic = "grid_symbolic.yaml";
  const std::string chroma_name = "chroma.yaml";
  const std::string chroma_symbolic = "chroma_symbolic.yaml";

  const std::string palette_file()
  {
    return data_directory / palettes / palette_name;
  }

  const std::string frame_file()
  {
    return data_directory / frames / derived / frame_name;
  }
  const std::string frame_symbolic_file()
  {
    return data_directory / frames / symbols / frame_symbolic;
  }

  const std::string layer_file()
  {
    return data_directory / layers / derived / layer_name;
  }

  const std::string layer_symbolic_file()
  {
    return data_directory / layers / symbols / layer_symbolic;
  }

  const std::string layer_symbolic_file(std::string name)
  {
    return data_directory / layers / symbols / name;
  }

  const std::string chroma_file()
  {
    return data_directory / chromas / derived / chroma_name;
  }

  const std::string chroma_symbolic_file()
  {
    return data_directory / chromas / symbols / chroma_symbolic;
  }

  const std::string grid_file()
  {
    return data_directory / grids / derived / grid_name;
  }

  const std::string grid_symbolic_file()
  {
    return data_directory / grids / symbols / grid_symbolic;
  }

  const std::string data_path()
  {
    return data_directory / "";
  }

  bool create_directory(std::string directory_name)
  {
    if (!std::filesystem::exists(data_directory))
    {
      std::error_code err;
      bool status = std::filesystem::create_directory(data_directory, err);
      if (status == false)
      {
        return false;
      }
    }
    return true;
  }

  bool make_file_system()
  {

    if (!create_directory(data_directory))
    {
      return false;
    }

    if (!create_directory(data_directory / palettes))
    {
      return false;
    }

    if (!create_directory(data_directory / frames))
    {
      return false;
    }
    if (!create_directory(data_directory / frames / symbols))
    {
      return false;
    }
    if (!create_directory(data_directory / frames / derived))
    {
      return false;
    }

    if (!create_directory(data_directory / layers))
    {
      return false;
    }
    if (!create_directory(data_directory / layers / symbols))
    {
      return false;
    }
    if (!create_directory(data_directory / layers / derived))
    {
      return false;
    }

    if (!create_directory(data_directory / grids))
    {
      return false;
    }
    if (!create_directory(data_directory / grids / symbols))
    {
      return false;
    }
    if (!create_directory(data_directory / grids / derived))
    {
      return false;
    }

    if (!create_directory(data_directory / chromas))
    {
      return false;
    }
    if (!create_directory(data_directory / chromas / symbols))
    {
      return false;
    }
    if (!create_directory(data_directory / chromas / derived))
    {
      return false;
    }

    return true;
  }

  bool file_system_exists()
  {
    if (!std::filesystem::exists(data_directory))
    {
      return false;
    }
    return true;
  }

  const std::string set_data_path(std::string path)
  {

    data_directory = path;
    return data_path();
  }
}