#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(float gravity, float jumpHeight)
    : gravidade(gravity), alturaPulo(jumpHeight){}

void PhysicsComponent::aplicaFisica(sf::Sprite& entidade, sf::Vector2f& velocidade, float deltaTime, bool& estaNoChao)
{
    // Aplica a gravidade
    velocidade.y += gravidade * deltaTime;

    // Atualiza posição (velocidade em y eh o quadrado do tempo * gravidade)
    entidade.move(velocidade * deltaTime);

    // Verifica colisão com o chao

    if(entidade.getPosition().y >= 500){
        entidade.setPosition(entidade.getPosition().x, 500);
        velocidade.y = 0;
        estaNoChao = true;
    }
}

float PhysicsComponent::getPulo()const
{
    return alturaPulo; 
}