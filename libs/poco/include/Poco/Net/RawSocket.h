//
// RawSocket.h
//
// $Id: //poco/1.3/Net/include/Poco/Net/RawSocket.h#1 $
//
// Library: Net
// Package: Sockets
// Module:  RawSocket
//
// Definition of the RawSocket class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Net_RawSocket_INCLUDED
#define Net_RawSocket_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/Socket.h"


namespace Poco {
namespace Net {


class Net_API RawSocket: public Socket
	/// This class provides an interface to a
	/// raw IP socket.
{
public:
	RawSocket();
		/// Creates an unconnected IPv4 raw socket.

	RawSocket(IPAddress::Family family, int proto = IPPROTO_RAW);
		/// Creates an unconnected raw socket.
		///
		/// The socket will be created for the
		/// given address family.

	RawSocket(const SocketAddress& address, bool reuseAddress = false);
		/// Creates a raw socket and binds it
		/// to the given address.
		///
		/// Depending on the address family, the socket
		/// will be either an IPv4 or an IPv6 socket.

	RawSocket(const Socket& socket);
		/// Creates the RawSocket with the SocketImpl
		/// from another socket. The SocketImpl must be
		/// a RawSocketImpl, otherwise an InvalidArgumentException
		/// will be thrown.

	~RawSocket();
		/// Destroys the RawSocket.

	RawSocket& operator = (const Socket& socket);
		/// Assignment operator.
		///
		/// Releases the socket's SocketImpl and
		/// attaches the SocketImpl from the other socket and
		/// increments the reference count of the SocketImpl.	

	void connect(const SocketAddress& address);
		/// Restricts incoming and outgoing
		/// packets to the specified address.
		///
		/// Cannot be used together with bind().

	void bind(const SocketAddress& address, bool reuseAddress = false);
		/// Bind a local address to the socket.
		///
		/// This is usually only done when establishing a server
		/// socket. 
		///
		/// If reuseAddress is true, sets the SO_REUSEADDR
		/// socket option.
		///
		/// Cannot be used together with connect().

	int sendBytes(const void* buffer, int length, int flags = 0);
		/// Sends the contents of the given buffer through
		/// the socket.
		///
		/// Returns the number of bytes sent, which may be
		/// less than the number of bytes specified.

	int receiveBytes(void* buffer, int length, int flags = 0);
		/// Receives data from the socket and stores it
		/// in buffer. Up to length bytes are received.
		///
		/// Returns the number of bytes received.

	int sendTo(const void* buffer, int length, const SocketAddress& address, int flags = 0);
		/// Sends the contents of the given buffer through
		/// the socket to the given address.
		///
		/// Returns the number of bytes sent, which may be
		/// less than the number of bytes specified.

	int receiveFrom(void* buffer, int length, SocketAddress& address, int flags = 0);
		/// Receives data from the socket and stores it
		/// in buffer. Up to length bytes are received.
		/// Stores the address of the sender in address.
		///
		/// Returns the number of bytes received.

	void setBroadcast(bool flag);
		/// Sets the value of the SO_BROADCAST socket option.
		///
		/// Setting this flag allows sending datagrams to
		/// the broadcast address.
	
	bool getBroadcast() const;
		/// Returns the value of the SO_BROADCAST socket option.

protected:
	RawSocket(SocketImpl* pImpl);
		/// Creates the Socket and attaches the given SocketImpl.
		/// The socket takes owership of the SocketImpl.
		///
		/// The SocketImpl must be a StreamSocketImpl, otherwise
		/// an InvalidArgumentException will be thrown.
};


//
// inlines
//
inline void RawSocket::setBroadcast(bool flag)
{
	impl()->setBroadcast(flag);
}


inline bool RawSocket::getBroadcast() const
{
	return impl()->getBroadcast();
}


} } // namespace Poco::Net


#endif // Net_RawSocket_INCLUDED
