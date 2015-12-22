/*
 * This file is part of gitg
 *
 * Copyright (C) 2015 - Jesse van den Kieboom
 *
 * gitg is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gitg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gitg. If not, see <http://www.gnu.org/licenses/>.
 */

#include "gitg-platform-support.h"

#include <gio/gwin32inputstream.h>

gboolean
gitg_platform_support_use_native_window_controls (GdkDisplay *display)
{
	return FALSE;
}

void
gitg_platform_support_http_get (GFile               *file,
                                GCancellable        *cancellable,
                                GAsyncReadyCallback  callback,
                                gpointer             user_data)
{
	g_file_read_async (file, G_PRIORITY_DEFAULT, cancellable, callback, user_data);
}

GInputStream *
gitg_platform_support_http_get_finish (GAsyncResult  *result,
                                       GError       **error)
{
	return G_INPUT_STREAM (g_file_read_finish (g_async_result_get_source_object (result), result, error));
}

cairo_surface_t *
gitg_platform_support_create_cursor_surface (GdkDisplay    *display,
                                             GdkCursorType  cursor_type,
                                             gint          *hot_x,
                                             gint          *hot_y,
                                             gint          *width,
                                             gint          *height)
{
	return NULL;
}

GInputStream *
gitg_platform_support_new_input_stream_from_fd (gint     fd,
                                                gboolean close_fd)
{
	return g_win32_input_stream_new ((void *)fd, close_fd);
}

gchar *
gitg_platform_support_get_lib_dir (void)
{
	gchar *module_dir;
	gchar *lib_dir;

	module_dir = g_win32_get_package_installation_directory_of_module (NULL);
	lib_dir = g_build_filename (module_dir, "lib", "gitg", NULL);
	g_free (module_dir);

	return lib_dir;
}

gchar *
gitg_platform_support_get_locale_dir (void)
{
	gchar *module_dir;
	gchar *locale_dir;

	module_dir = g_win32_get_package_installation_directory_of_module (NULL);
	locale_dir = g_build_filename (module_dir, "share", "locale", NULL);
	g_free (module_dir);

	return locale_dir;
}

gchar *
gitg_platform_support_get_data_dir (void)
{
	gchar *module_dir;
	gchar *data_dir;

	module_dir = g_win32_get_package_installation_directory_of_module (NULL);
	data_dir = g_build_filename (module_dir, "share", "gitg", NULL);
	g_free (module_dir);

	return data_dir;
}

gchar *
gitg_platform_support_get_user_home_dir (const gchar *name)
{
	// TODO
	return NULL;
}

// ex:ts=4 noet