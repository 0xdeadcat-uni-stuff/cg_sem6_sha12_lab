#pragma once
class Particle
{
private:
	float age;
	float deathTime;
	float sPosX;
	float sPosY;
	float sPosZ;
	float phaseX;
	float phaseY;
	//***** TODO *****//
public:
	Particle() = delete;
	Particle(float _deathTime, float _sPosX, float _sPosY, float _sPosZ, float _phaseX, float _phaseY) : age(0), deathTime(_deathTime),
		sPosX(_sPosX), sPosY(_sPosY), sPosZ(_sPosZ),
		phaseX(_phaseX), phaseY(_phaseY)
	{};
	virtual void operator()(float* vertices, int& index, float dT, bool updateAge = true);
	virtual bool isDeath() { return age > deathTime; };
	static int VerticesPerParticle() { return 1; }
	static int VertexDimentionality() { return 10; }

	//***** TODO *****//
	
	~Particle();
};

