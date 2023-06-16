/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:50:51 by btchiman          #+#    #+#             */
/*   Updated: 2023/06/12 15:50:57 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(void)
{
    return ;
}

Channel::Channel(std::string name) : _name(name)
{
    // initialiser d'autres attributs du canal, configurer des paramètres, etc.
    return ;
}

Channel::Channel(const Channel& other)
{
    *this = other;
    return ;
}

Channel &Channel::operator=(const Channel &other)
{
    this->_name = other._name;
    this->_clients = other._clients;
    return (*this);
}

Channel::~Channel()
{
    return ;
}

std::string Channel::getName(void) const
{
    return (this->_name);
}

void Channel::setName(std::string name)
{
    this->_name = name;
}

void Channel::addClient(Client *client)
{
    this->_clients.push_back(client);
}

void Channel::removeClient(Client *client)
{
    std::vector<Client *>::iterator it;

    it = std::find(this->_clients.begin(), this->_clients.end(), client);
    if (it != this->_clients.end())
        this->_clients.erase(it);
}

std::vector<Client *> Channel::getClients(void) const
{
    return (this->_clients);
}

void Channel::setPassword(std::string password)
{
    this->_password = password;
}

std::string Channel::getPassword(void) const
{
    return (this->_password);
}

void Channel::setMode(std::string mode)
{
    this->_mode = mode;
}

std::string Channel::getMode(void) const
{
    return (this->_mode);
}

void Channel::addOperator(Client *client)
{
    this->_operators.push_back(client);
}

std::vector<Client *> Channel::getOperators(void) const
{
    return (this->_operators);
}

void Channel::removeOperator(Client *client)
{
    std::vector<Client *>::iterator it;

    it = std::find(this->_operators.begin(), this->_operators.end(), client);
    if (it != this->_operators.end())
        this->_operators.erase(it);
}

void Channel::addBanned(int fd)
{
    this->_banned.push_back(fd);
}

std::vector<int> Channel::getBanned(void) const
{
    return (this->_banned);
}

void Channel::addInvite(int fd)
{
    this->_invite.push_back(fd);
}

std::vector<int> Channel::getInvite(void) const
{
    return (this->_invite);
}

void Channel::removeBanned(int fd)
{
    std::vector<int>::iterator it;

    it = std::find(this->_banned.begin(), this->_banned.end(), fd);
    if (it != this->_banned.end())
        this->_banned.erase(it);
}