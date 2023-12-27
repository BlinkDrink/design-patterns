#include "ProxyLabel.h"

#include <iostream>
#include <stdexcept>

namespace Problem2
{
	namespace Labels
	{
		using std::cin;
		using std::endl;
		using std::cout;
		using std::getline;
		using std::make_unique;
		using std::invalid_argument;

		ProxyLabel::ProxyLabel(int timeout) : m_real_label(nullptr), m_timeout_threshold(timeout), m_request_count(0), m_prompt_user(false)
		{
			if (timeout <= 0)
				throw invalid_argument("Timeout must be a positive integer");
		}

		string ProxyLabel::getText() const
		{
			if (!m_real_label)
			{
				string input;
				cout << "Enter label text: ";
				getline(cin, input);

				m_real_label = make_unique<SimpleLabel>(input);
			}

			m_request_count++;

			if (m_request_count >= m_timeout_threshold && !m_prompt_user)
			{
				char choice = '\0';

				while (choice != 'y' && choice != 'n')
				{
					cout << "You have reached the timeout threshold. Do you want to change the label text? (y/n): ";
					cin >> choice;

					if (choice == 'y')
					{
						string text;
						cout << "Enter new label text: ";
						cin.ignore();
						getline(cin, text);
						m_real_label.reset(new SimpleLabel(text));
					}
					else if (choice == 'n')
					{
						cout << "Keeping the current text..." << endl;
						cin.ignore();
					}
					else
					{
						cout << "Invalid option.";
						cin.ignore();
					}
				}
				m_prompt_user = true;
				m_request_count = 0;
			}

			return m_real_label->getText();
		}

		bool ProxyLabel::operator==(const Label& other) const
		{
			const ProxyLabel* cast = dynamic_cast<const ProxyLabel*>(&other);
			if (!cast)
				return false;

			return m_timeout_threshold == cast->m_timeout_threshold &&
				m_prompt_user == cast->m_prompt_user &&
				m_request_count == cast->m_request_count &&
				*m_real_label == *(cast->m_real_label);
		}
	}
}

