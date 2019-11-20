#include <iostream>

#include <osmium/io/any_input.hpp>
#include <osmium/osm/entity_bits.hpp>
#include <osmium/osm/way.hpp>

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " OSMFILE\n";
    exit(1);
  }

  osmium::io::Reader reader(argv[1], osmium::osm_entity_bits::way);

  while (osmium::memory::Buffer buffer = reader.read())
  {
    for (const auto &item : buffer)
    {
      const osmium::Way &way = static_cast<const osmium::Way&>(item);

      const char *name = way.get_value_by_key("name");
      const char *highway = way.get_value_by_key("highway");
      if (name && highway)
        std::cout << "[" << way.user() << "] " << name << "\n";
    }
  }

  reader.close();

  google::protobuf::ShutdownProtobufLibrary();
}
