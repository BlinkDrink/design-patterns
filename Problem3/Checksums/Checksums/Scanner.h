#pragma once

namespace Checksums
{
	namespace Scanners
	{
		/**
		 * \brief Base class for Template method. We can have HashStreamWriter scanner and ReportWriter Scanner.
		 */
		class Scanner
		{
		public:
			void scan();
		};
	}
}
