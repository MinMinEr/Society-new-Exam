/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-plugin-factory.c -- Autogenerated from libanjuta.idl
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
 * SECTION:ianjuta-plugin-factory
 * @title: IAnjutaPluginFactory
 * @short_description: Create Anjuta plugin objects
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-plugin-factory.h
 *
 * This interface is used to create all Anjuta plugin objects. It is
 * already implemented inside Anjuta by an object able to load plugins written
 * in C. In order to load plugins in other languages (or in a different way),
 * a loader plugin implementing this interface must be written first, probably
 * in C.
 */

#include "ianjuta-plugin-factory.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_plugin_factory_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-plugin-factory-quark");
	}
	
	return quark;
}

/**
 * ianjuta_plugin_factory_new_plugin:
 * @obj: Self
 * @handle: Plugin information
 * @shell: Anjuta shell
 * @err: Error propagation and reporting.
 *
 * Create a new AnjutaPlugin object from the plugin information handle,
 * give it the AnjutaShell object as argument.
 *
 * Return value: a new plugin object
 */
AnjutaPlugin*
ianjuta_plugin_factory_new_plugin (IAnjutaPluginFactory *obj, AnjutaPluginHandle* handle,   AnjutaShell *shell, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PLUGIN_FACTORY(obj), NULL);
	g_return_val_if_fail ((handle == NULL) ||ANJUTA_IS_PLUGIN_HANDLE(handle), NULL);
	g_return_val_if_fail ((shell == NULL) ||ANJUTA_IS_SHELL(shell), NULL);
	return IANJUTA_PLUGIN_FACTORY_GET_IFACE (obj)->new_plugin (obj, handle, shell, err);
}

/* Default implementation */
static AnjutaPlugin*
ianjuta_plugin_factory_new_plugin_default (IAnjutaPluginFactory *obj, AnjutaPluginHandle* handle,   AnjutaShell *shell, GError **err)
{
	g_return_val_if_reached (NULL);
}

static void
ianjuta_plugin_factory_base_init (IAnjutaPluginFactoryIface* klass)
{
	static gboolean initialized = FALSE;

	klass->new_plugin = ianjuta_plugin_factory_new_plugin_default;
	
	if (!initialized) {

		initialized = TRUE;
	}
}

GType
ianjuta_plugin_factory_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaPluginFactoryIface),
			(GBaseInitFunc) ianjuta_plugin_factory_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaPluginFactory", &info, 0);
		g_type_interface_add_prerequisite (type, G_TYPE_OBJECT);
	}
	return type;			
}

GType
ianjuta_plugin_factory_error_get_type (void)
{
	static const GEnumValue values[] =
	{
		{ IANJUTA_PLUGIN_FACTORY_OK, "IANJUTA_PLUGIN_FACTORY_OK", "ok" }, 
		{ IANJUTA_PLUGIN_FACTORY_MISSING_LOCATION, "IANJUTA_PLUGIN_FACTORY_MISSING_LOCATION", "missing-location" }, 
		{ IANJUTA_PLUGIN_FACTORY_MISSING_TYPE, "IANJUTA_PLUGIN_FACTORY_MISSING_TYPE", "missing-type" }, 
		{ IANJUTA_PLUGIN_FACTORY_MISSING_MODULE, "IANJUTA_PLUGIN_FACTORY_MISSING_MODULE", "missing-module" }, 
		{ IANJUTA_PLUGIN_FACTORY_INVALID_MODULE, "IANJUTA_PLUGIN_FACTORY_INVALID_MODULE", "invalid-module" }, 
		{ IANJUTA_PLUGIN_FACTORY_MISSING_FUNCTION, "IANJUTA_PLUGIN_FACTORY_MISSING_FUNCTION", "missing-function" }, 
		{ IANJUTA_PLUGIN_FACTORY_INVALID_TYPE, "IANJUTA_PLUGIN_FACTORY_INVALID_TYPE", "invalid-type" }, 
		{ IANJUTA_PLUGIN_FACTORY_UNKNOWN_ERROR, "IANJUTA_PLUGIN_FACTORY_UNKNOWN_ERROR", "unknown-error" }, 
		{ 0, NULL, NULL }
	};

	static GType type = 0;

	if (! type)
	{
		type = g_enum_register_static ("IAnjutaPluginFactoryError", values);
	}

	return type;
}
