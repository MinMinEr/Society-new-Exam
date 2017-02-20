/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-debug-manager.c -- Autogenerated from libanjuta.idl
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
* SECTION:ianjuta-debug-manager
* @title: IAnjutaDebugManager
* @short_description: Common graphical interface to all debugger
* @see_also:
* @stability: Unstable
* @include: libanjuta/interfaces/ianjuta-debug-manager.h
*
* This interface wrap the real debugger plugin and provide a
* common graphical user interface.
*/

#include "ianjuta-debug-manager.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_debug_manager_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-debug-manager-quark");
	}
	
	return quark;
}

/**
* ianjuta_debug_manager_quit:
* @obj: Self
* @err: Error propagation and reporting.
*
* Quit the debugger, can wait until the debugger is ready.
*
* Returns: TRUE if sucessful, other FALSE.
*/
gboolean
ianjuta_debug_manager_quit (IAnjutaDebugManager *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_DEBUG_MANAGER(obj), FALSE);
	return IANJUTA_DEBUG_MANAGER_GET_IFACE (obj)->quit (obj, err);
}

/* Default implementation */
static gboolean
ianjuta_debug_manager_quit_default (IAnjutaDebugManager *obj, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
* ianjuta_debug_manager_start:
* @obj: Self
* @uri: uri of the target
* @err: Error propagation and reporting.
*
* Start the debugger of the given uri
*
* Returns: TRUE if sucessful, other FALSE.
*/
gboolean
ianjuta_debug_manager_start (IAnjutaDebugManager *obj, const gchar *uri, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_DEBUG_MANAGER(obj), FALSE);
	return IANJUTA_DEBUG_MANAGER_GET_IFACE (obj)->start (obj, uri, err);
}

/* Default implementation */
static gboolean
ianjuta_debug_manager_start_default (IAnjutaDebugManager *obj, const gchar *uri, GError **err)
{
	g_return_val_if_reached (FALSE);
}

   /**
* ianjuta_debug_manager_start_remote:
* @obj: Self
* @server: server (IP address:port)
* @uri: uri of the local target
* @err: Error propagation and reporting.
*
* Start the debugger of the given uri
*
* Returns: TRUE if sucessful, other FALSE.
*/
gboolean
ianjuta_debug_manager_start_remote (IAnjutaDebugManager *obj, const gchar *server,   const gchar *uri, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_DEBUG_MANAGER(obj), FALSE);
	return IANJUTA_DEBUG_MANAGER_GET_IFACE (obj)->start_remote (obj, server, uri, err);
}

/* Default implementation */
static gboolean
ianjuta_debug_manager_start_remote_default (IAnjutaDebugManager *obj, const gchar *server,   const gchar *uri, GError **err)
{
	g_return_val_if_reached (FALSE);
}

static void
ianjuta_debug_manager_base_init (IAnjutaDebugManagerIface* klass)
{
	static gboolean initialized = FALSE;

	klass->quit = ianjuta_debug_manager_quit_default;
	klass->start = ianjuta_debug_manager_start_default;
	klass->start_remote = ianjuta_debug_manager_start_remote_default;
	
	if (!initialized) {

		/**
		* IAnjutaDebugManager::breakpoint_changed:
		* @obj: Self
		* @breakpoint: Breakpoint
		* @err: Error propagation and reporting.
		*
		* This signal is emitted when a breakpoint is changed. It includes
		* new breakpoint and deleted breakpoint.
		*/
		g_signal_new ("breakpoint-changed",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, breakpoint_changed),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__POINTER,
			G_TYPE_NONE,
			1,
			G_TYPE_POINTER);


		/* Signals */
		/**
		* IAnjutaDebugManager::debugger_started:
		* @obj: Self
		*
		* This signal is emitted when the debugger is started.
		*/
		g_signal_new ("debugger-started",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, debugger_started),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::debugger_stopped:
		* @obj: Self
		* @err: Error propagation and reporting.
		*
		* This signal is emitted when the debugger is stopped.
		*/
		g_signal_new ("debugger-stopped",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, debugger_stopped),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__BOXED,
			G_TYPE_NONE,
			1,
			G_TYPE_ERROR);


		/**
		* IAnjutaDebugManager::frame_changed:
		* @obj: Self
		* @frame: frame
		* @thread: thread
		*
		* This signal is emitted when the current frame is changed. It is
		* equal to the top frame in the interrupted thread when the
		* program stops but can be changed afterward by the user.
		* Several commands use this current frame, by example the register
		* window display the register values for the current thread only.
		*/
		g_signal_new ("frame-changed",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, frame_changed),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__UINT_INT,
			G_TYPE_NONE,
			2,
			G_TYPE_UINT,
			G_TYPE_INT);


		/**
		* IAnjutaDebugManager::location_changed:
		* @obj: Self
		* @address: program counter address, 0 when unknown
		* @uri: source file where is the program counter, NULL when unknown
		* @line: line number if file name above is not NULL
		*
		* This signal is emitted when the current location is changed. It is
		* equal to the program location when the program stops but can be
		* changed afterward by the user.
		*/
		g_signal_new ("location-changed",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, location_changed),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__ULONG_STRING_UINT,
			G_TYPE_NONE,
			3,
			G_TYPE_ULONG,
			G_TYPE_STRING,
			G_TYPE_UINT);


		/**
		* IAnjutaDebugManager::program_exited:
		* @obj: Self
		*
		* This signal is emitted when the program is unloaded. If the
		* debugger is stopped while a program is running or stopped, this
		* signal is emitted before the program_unloaded signal.
		*/
		g_signal_new ("program-exited",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_exited),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::program_loaded:
		* @obj: Self
		*
		* This signal is emitted when a program is loaded most of the
		* time just before the first program_stopped signal.
		*/
		g_signal_new ("program-loaded",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_loaded),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::program_moved:
		* @obj: Self
		 	* @pid: process id, 0 when unknown
		* @tid: thread id, 0 when unknown
		* @address: program counter address, 0 when unknown
		* @file: source file where is the program counter, NULL when unknown
		* @line: line number if file name above is not NULL
		*
		* This signal is emitted when the debugger know the current program
		* location. Most of the time, after the program has stopped but it
		* could happen even if it is still running.
		*/
		g_signal_new ("program-moved",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_moved),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__INT_INT_ULONG_STRING_UINT,
			G_TYPE_NONE,
			5,
			G_TYPE_INT,
			G_TYPE_INT,
			G_TYPE_ULONG,
			G_TYPE_STRING,
			G_TYPE_UINT);


		/**
		* IAnjutaDebugManager::program_running:
		* @obj: Self
		*
		* This signal is emitted when the program is running.
		*/
		g_signal_new ("program-running",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_running),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::program_started:
		* @obj: Self
		*
		* This signal is emitted when the program is started. If the
		* program starts and is stopped by the debugger, a program-stopped
		* signal will be emitted too. If the program starts is not stopped
		* by the debugger a program-running signal will be emitted.
		*/
		g_signal_new ("program-started",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_started),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::program_stopped:
		* @obj: Self
		*
		* This signal is emitted when the program is stopped.
		*/
		g_signal_new ("program-stopped",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_stopped),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::program_unloaded:
		* @obj: Self
		*
		* This signal is emitted when a program is unloaded. If the
		* debugger is stopped while a program is loaded, this signal
		* is emitted before the debugger_stopped signal.
		*/
		g_signal_new ("program-unloaded",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, program_unloaded),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::sharedlib_event:
		* @obj: Self
		*
		* This signal is emitted when a new shared library is loaded. It
		* is useful to try to set pending breakpoints those could be in
		* the newly loaded library.
		*/
		g_signal_new ("sharedlib-event",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, sharedlib_event),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		/**
		* IAnjutaDebugManager::signal_received:
		* @obj: Self
		* @name: Signal name
		* @description: Signal description
		*
		* This signal is emitted when the debugged program receives a
		* unix signal.
		*/
		g_signal_new ("signal-received",
			IANJUTA_TYPE_DEBUG_MANAGER,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaDebugManagerIface, signal_received),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__STRING_STRING,
			G_TYPE_NONE,
			2,
			G_TYPE_STRING,
			G_TYPE_STRING);


		initialized = TRUE;
	}
}

GType
ianjuta_debug_manager_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaDebugManagerIface),
			(GBaseInitFunc) ianjuta_debug_manager_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaDebugManager", &info, 0);
		g_type_interface_add_prerequisite (type, G_TYPE_OBJECT);
	}
	return type;			
}
