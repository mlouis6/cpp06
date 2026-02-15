#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class Serializer
{
    public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

    private:
		Serializer();
		Serializer(const Serializer& cpy);
		Serializer& operator=(const Serializer& cpy);
		~Serializer();
};

#endif
