using System;
using System.Text;
using System.Runtime.InteropServices;

namespace Source.Public
{
	static public class FileSystem
	{
		public static void AddSearchPath(string path, string pathid)
		{
			FSNative.fs_add_search_path(path, pathid);
		}

		public static void RemoveSearchPath(string path, string pathid)
		{
			FSNative.fs_remove_search_path(path, pathid);
		}
	}
}

